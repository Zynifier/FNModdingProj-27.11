// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortCustomPartTypeEnum.h"
#include "FortAnimNotifyState_MissingCosmeticAnimOverride.generated.h"

class UAnimInstance;
class UAnimSequence;

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_MissingCosmeticAnimOverride : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_MissingCosmeticAnimOverride")
	TSubclassOf<UAnimInstance> RequiredAnimInstanceClass;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_MissingCosmeticAnimOverride")
	TEnumAsByte<EFortCustomPartType::Type> PartTypeToCheck;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> UpperBodyOverride;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> LowerBodyOverride;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> LowerBodyInMotionOverride;

};

