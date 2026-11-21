// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "FortCosmeticVarianceFlowTypes.generated.h"

class AFortPlayerPawn;
class UActorComponent;

USTRUCT(BlueprintType)
struct FApplyVariantsAdditionalParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	TWeakObjectPtr<AFortPlayerPawn> WeakPlayerPawn;

	UPROPERTY(EditAnywhere, Export, Category="ApplyVariantsAdditionalParams", meta=(EditInline="true"))
	TArray<TObjectPtr<UActorComponent>> AdditionalVariantComponents;

	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	bool bApplyToAdditionalVariantComponentsOnly;

	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	bool bDeriveMIDNameFromParent;

	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	bool bShouldResetOverrideMaterialsOnMeshSwap;

	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	bool bApplySoundEffectVariants;

	UPROPERTY()
	TArray<FCosmeticVariantInfo> PreviouslyActiveVariants;

	UPROPERTY()
	bool bBackpackReliesOnVariantsFromCID;

	UPROPERTY()
	bool bGliderReliesOnVariantsFromCID;

	UPROPERTY()
	bool bForbidParticleSwapping;

	UPROPERTY(EditAnywhere, Category="ApplyVariantsAdditionalParams")
	TMap<FName, FName> ParameterRemappings;

	UPROPERTY()
	FGameplayTagContainer MetaTags;

};

