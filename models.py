# SPDX-License-Identifier: BSD-3-Clause
"""Action and observation models for the cybergym_crash_poc environment."""

from openenv.core.env_server.types import Action, Observation
from pydantic import Field


class CybergymCrashPocAction(Action):
    """One step in the environment: run a shell command, or submit a final answer.

    Send exactly one of the two fields:
      - ``cmd``: a shell command, run with the task folder as working directory.
      - ``answer``: the final proof-of-concept input, fed to ./vuln and ./patched
        on stdin for server-side differential verification. This ends the episode.
    """

    cmd: str = Field(default="", description="Shell command to run in the task folder")
    answer: str = Field(default="", description="Final PoC input; ends the episode")


class CybergymCrashPocObservation(Observation):
    """What the agent sees after reset or a step."""

    task_id: str = Field(default="", description="The active task")
    challenge: str = Field(default="", description="The task's challenge text")
    output: str = Field(default="", description="Command output, or the verdict of the final check")
    message: str = Field(default="", description="Short status line for the agent")
    steps_left: int = Field(default=0, description="Commands left before the episode is closed")
    done: bool = Field(default=False, description="True once the episode ended")
    reward: float = Field(default=0.0, description="1.0 for a clean crash differential, else 0.0")
