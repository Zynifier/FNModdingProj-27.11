// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_SyncedEmoteAlign.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_SyncedEmoteAlign : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_SyncedEmoteAlign")
	FName JointToAlign;

	UPROPERTY(VisibleAnywhere, Category="FortAnimNotifyState_SyncedEmoteAlign")
	FName JointToMove;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_SyncedEmoteAlign")
	float MoveLimit;

};

