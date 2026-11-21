// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PhaseCommitEnums.generated.h"

UENUM()
enum class ECoordinatorBroadcasts : uint8
{
	ReadyForRequests = 0,
	BeginStateChange_TwoPhase = 1,
	BeginStateChange_ThreePhase = 2,
	PreCommit = 3,
	Success = 4,
	Aborted = 5,
};

UENUM()
enum class EParticipantResponses : uint8
{
	NONE = 0,
	AcceptedBegin = 1,
	RejectedBegin = 2,
	AcceptedPreCommit = 3,
	RejectedPreCommit = 4,
	ReceivedSuccess = 5,
	ReceivedAbort = 6,
};

UENUM()
enum class EPhaseCommit : uint8
{
	//////////////////////////////////////////////////////////////////////////
// Coordinator will simply commit the change without participant acknowledgement

	One = 0,
	//////////////////////////////////////////////////////////////////////////
// Coordinator will wait for Participant acknowledgment 
// Coordinator will send the Participant an acknowledgment confirmation

	Two = 1,
	//////////////////////////////////////////////////////////////////////////
// Coordinator will wait for all Participants acknowledgments
// Coordinator will notify all Participants when all Participants have sent acknowledgments
// Coordinator will wait for "ReadyToCommit" from all Participants before committing
// Will automatically downgrade to a Two-Phase Commit if there is only a single Participant

	Three = 2,
};

