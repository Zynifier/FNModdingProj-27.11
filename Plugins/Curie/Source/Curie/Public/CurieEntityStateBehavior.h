// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CurieTypes.h"
#include "CurieEntityStateBehavior.generated.h"

UCLASS(Abstract, Const, BlueprintType, Blueprintable, ClassGroup=("Curie"))
class CURIE_API UCurieEntityStateBehavior : public UCurieElementGameplayEffectOwner
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(Categories="CurieElement"))
	FGameplayTagContainer RequiredAttachedElements;

	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(Categories="CurieElement"))
	FGameplayTagContainer RequiredInteractingElements;

	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(Categories="CurieElement,CurieMaterial"))
	FGameplayTagContainer AllowedAttachmentEntityTypes;

	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(EditCondition="!bSkipExecuteAttachDetach"))
	TArray<FCurieEffectContainer> OnBeginEffects;

	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(EditCondition="!bSkipExecuteAttachDetach"))
	TArray<FCurieEffectContainer> OngoingEffects;

	UPROPERTY(EditDefaultsOnly, Category="CurieState", meta=(EditCondition="!bSkipExecuteAttachDetach"))
	TArray<FCurieEffectContainer> OnEndEffects;

	UPROPERTY(EditDefaultsOnly, Category="Advanced")
	uint8 bShouldDetach : 1;

	UPROPERTY(EditDefaultsOnly, Category="Advanced")
	uint8 bSkipExecuteAttachDetach : 1;

};

