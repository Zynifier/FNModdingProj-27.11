// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkProtocol.generated.h"

UENUM()
enum class EDecodeType : uint8
{
	DecodeNone = 0,
	DecodeWebCamLo = 1,
};

UENUM()
enum class EWebCamMessageServiceSenderState : uint8
{
	None = 0,
	Connecting = 1,
	SentHello = 2,
	Connected = 3,
};

UENUM()
enum class EWebCameraMessageType : uint8
{
	/** None. */
	None = 0,
	/** Notifies a new connection has joined */
	SC_Welcome = 1,
	CS_WebCamReaderReady = 2,
	CS_WebCamViewerReady = 3,
	SC_RequestWebCamUpdates = 4,
	CS_HereIsWebCamUpdate = 5,
	SC_MakeReadyToReceiveWebCamUpdates = 6,
	SC_HereIsWebCamUpdate = 7,
	CS_StillAlive = 8,
	CS_ChangeWebCamViewerPlayer = 9,
	CS_EndConnection = 10,
};

