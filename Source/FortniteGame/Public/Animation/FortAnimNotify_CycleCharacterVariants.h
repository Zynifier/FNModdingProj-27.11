// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotify_CycleCharacterVariants.generated.h"

class UAthenaCosmeticItemDefinition;

USTRUCT()
struct FFortCosmeticVariantTransition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Swapping Rules", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag ChannelWithin;

	UPROPERTY(EditAnywhere, Category="Swapping Rules", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag VariantFrom;

	UPROPERTY(EditAnywhere, Category="Swapping Rules", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag VariantTo;

};

USTRUCT()
struct FFortCosmeticVariantSwapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Swapping")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> ItemToManage;

	UPROPERTY(EditAnywhere, Category="Variant Swapping")
	TArray<FFortCosmeticVariantTransition> Transitions;

};

UCLASS(HideCategories=("Object"), meta=(DisplayName="Swap Active Character Variant (Complex)"))
class UFortAnimNotify_CycleCharacterVariants : public UAnimNotify
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Variant Swapping", meta=(TitleProperty="ItemToManage"))
	TArray<FFortCosmeticVariantSwapData> TransitionData;

};

