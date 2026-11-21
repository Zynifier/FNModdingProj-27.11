// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticRichColorVariant.generated.h"

UENUM()
enum class EFortRichColorConflictResolutionRules : uint8
{
	/** Colors cannot be the exact same value */
	NoConflictsAllowed = 0,
	/** Multiple colors cannot be black or white */
	BlackOrWhiteCannotConflict = 1,
	/**  Colors must be at least some amount different from each other or not be black or white(same as original elastic model, but larger tolerance) */
	MinimumDistanceBlackOrWhite = 2,
	/** Colors must have a minimum contrast ratio */
	MinimumContrast = 3,
	/** Colors must have a minimum contrast ratio, hue shift, or saturation shift */
	MinimumContrastOrHueSaturationShift = 4,
	/** Grayscale colors must have a minimum contrast ratio */
	MinimumContrastGrayscale = 5,
};

UCLASS(MinimalAPI)
class UFortCosmeticRichColorVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts")
	int32 AntiConflictChannel;

	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts", meta=(ClampMax="2.0", ClampMin="0.0", EditCondition="AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumDistanceBlackOrWhite", EditConditionHides))
	float MinimumDistance;

	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts", meta=(ClampMax="21.0", ClampMin="1.0", EditCondition="AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumContrast || AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumContrastOrHueSaturationShift || AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumContrastGrayscale", EditConditionHides))
	float MinimumContrast;

	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts", meta=(ClampMax="180.0", ClampMin="0.0", EditCondition="AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumContrastOrHueSaturationShift", EditConditionHides))
	float MinimumHueShift;

	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts", meta=(ClampMax="1.0", ClampMin="0.0", EditCondition="AntiConflictRules == EFortRichColorConflictResolutionRules::MinimumContrastOrHueSaturationShift", EditConditionHides))
	float MinimumSaturationShift;

	UPROPERTY(EditAnywhere, Category="Cosmetics|Conflicts")
	EFortRichColorConflictResolutionRules AntiConflictRules;

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetics")
	FRichColorVariantDef InlineVariant;

};

