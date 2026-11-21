// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_ConsumeSound.generated.h"

class USoundBase;

UCLASS(HideCategories=("Object"), meta=(DisplayName="Consume Audio Notify State Athena"))
class UFortAnimNotifyState_ConsumeSound : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sound")
	TObjectPtr<USoundBase> ConsumeUseSound;

};

