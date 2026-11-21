// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Creative/DAD/DAD_CreativeUserOptions.h"
#include "FortGender.h"
#include "DAD_CosmeticItemUserOptions.generated.h"

class UAnimSequenceBase;
class UFortItemDefinition;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDAD_CosmeticItemUserOption : public FDAD_BaseCreativeUserOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_CosmeticItemUserOption")
	TSoftObjectPtr<UFortItemDefinition> CosmeticItemAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_CosmeticItemUserOption")
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_CosmeticItemUserOption")
	FGameplayTagContainer DefaultVariants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_CosmeticItemUserOption")
	FLinearColor VFXColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_CosmeticItemUserOption")
	FString StoreLink;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortAnimationsPerGender
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAnimationsPerGender")
	TMap<TEnumAsByte<EFortCustomGender::Type>, TSoftObjectPtr<UAnimSequenceBase>> GenderAnimations;

};

UCLASS()
class UDAD_CosmeticItemUserOptions : public UDAD_CreativeUserOptions
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TArray<FDAD_CosmeticItemUserOption>& GetCosmetics() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_CosmeticItemUserOptions", meta=(Patchable))
	TArray<FDAD_CosmeticItemUserOption> CosmeticItemUserOptionsList;

};

UCLASS(BlueprintType, Blueprintable)
class UDAD_GenderAnimationUserOptionAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UAnimSequenceBase> GetAnimationForGender(const EFortCustomGender::Type Gender = EFortCustomGender::Both) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_GenderAnimationUserOptionAsset")
	FFortAnimationsPerGender GenderAnimation;

};

