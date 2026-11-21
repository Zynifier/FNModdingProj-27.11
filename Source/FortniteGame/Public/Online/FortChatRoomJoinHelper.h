// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortChatRoomJoinHelper.generated.h"

class USocialChatChannel;

UENUM()
enum class EChatRoomJoinHelperState : uint8
{
	Ready = 0,
	AttemptingJoin = 1,
	Joined = 2,
	AttemptingLeave = 3,
};

UCLASS()
class UFortChatRoomJoinHelper : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<USocialChatChannel> JoinedChannel;

};

