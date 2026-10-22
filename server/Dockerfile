# SPDX-License-Identifier: BSD-3-Clause

# OpenEnv environment image for cybergym_crash_poc.
# Build: DOCKER_DEFAULT_PLATFORM=linux/amd64 openenv build -t ghcr.io/<you>/cybergym-crash-poc:v1

ARG BASE_IMAGE=ghcr.io/huggingface/openenv-base:latest
FROM ${BASE_IMAGE} AS builder

WORKDIR /app

RUN apt-get update && \
    apt-get install -y --no-install-recommends git && \
    rm -rf /var/lib/apt/lists/*

COPY . /app/env
WORKDIR /app/env

RUN if ! command -v uv >/dev/null 2>&1; then \
        curl -LsSf https://astral.sh/uv/install.sh | sh && \
        mv /root/.local/bin/uv /usr/local/bin/uv && \
        mv /root/.local/bin/uvx /usr/local/bin/uvx; \
    fi

RUN --mount=type=cache,target=/root/.cache/uv \
    uv sync --no-install-project --no-editable && \
    uv sync --no-install-project --no-editable --frozen 2>/dev/null || \
    uv sync --no-install-project --no-editable; \
    true

RUN --mount=type=cache,target=/root/.cache/uv \
    uv sync --no-editable || true

RUN mv /app/env/.venv /app/.venv

FROM ${BASE_IMAGE}

WORKDIR /app

# gcc stays in the image: agents may compile and experiment with the task sources.
RUN apt-get update && \
    apt-get install -y --no-install-recommends gcc libc6-dev && \
    rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/.venv /app/.venv
COPY --from=builder /app/env /app/env
RUN ln -s /app/.venv /app/env/.venv

# Compile the vulnerable and patched builds of every task into the image.
RUN cd /app/env/server && sh build_tasks.sh

ENV PATH="/app/.venv/bin:$PATH"
ENV PYTHONPATH="/app/env:$PYTHONPATH"
ENV CRASH_POC_TASKS="/app/env/server/tasks"

EXPOSE 8000

HEALTHCHECK --interval=30s --timeout=3s --start-period=5s --retries=3 \
    CMD curl -f http://localhost:8000/health || exit 1

CMD ["sh", "-c", "cd /app/env && uvicorn server.app:app --host 0.0.0.0 --port 8000"]
