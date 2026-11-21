// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_EmoteProximityGroup.generated.h"

class USoundBase;

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_EmoteProximityGroup : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Group Settings")
	FName GroupName;

	UPROPERTY(EditAnywhere, Category="Group Settings")
	float GroupMaxRange;

	UPROPERTY(EditAnywhere, Category="Group Settings")
	int32 GroupMaxSize;

	UPROPERTY(EditAnywhere, Category="Audio")
	TObjectPtr<USoundBase> SoundOnEnterGroup;

	UPROPERTY(EditAnywhere, Category="Audio")
	TObjectPtr<USoundBase> SoundOnExitGroup;

};

