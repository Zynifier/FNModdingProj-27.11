// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_PlayPetMontage.generated.h"

class UPetSyncedDanceItemDefinition;

UCLASS(HideCategories=("Object"), meta=(DisplayName="Play Pet Montage"))
class UFortAnimNotifyState_PlayPetMontage : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_PlayPetMontage")
	TObjectPtr<UPetSyncedDanceItemDefinition> PetDance;

};

