// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "SFortMakeDesignPerkAssetForm.generated.h"

UENUM()
enum class EPerkCreationHeroType : uint8
{
	Hero = 0,
	Leader = 1,
};

USTRUCT()
struct FPerkItemDefinitionDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PerkItemDefinitionDesignerData")
	EPerkCreationHeroType HeroType;

	UPROPERTY(EditAnywhere, Category="PerkItemDefinitionDesignerData")
	FName PerkName;

	UPROPERTY(EditAnywhere, Category="PerkItemDefinitionDesignerData")
	int32 NumGameplayAbilitiesToCreate;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bOpenAssetsForEdit;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bNeverPersisted;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateGameplayAbilityPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateGameplayEffectPath;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	FSoftObjectPath TemplateTooltipPath;

};

