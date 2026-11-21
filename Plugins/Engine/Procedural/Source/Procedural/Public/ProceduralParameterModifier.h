// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralParameterModifierBlendMode.h"
#include "ProceduralParameterModifier.generated.h"

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralParameterModifier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Procedural Parameter Modifier")
	float GetContribution() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier")
	bool bEnabled;

	/** Effect on result in percentage. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(ClampMax="100.0", ClampMin="0.0", UIMax="100.0", UIMin="0.0", Units="%"))
	float Contribution;

	/** Blend mode used to combine mapping data with previous mapping data (ignored if only 1 map). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier")
	EProceduralParameterModifierBlendMode BlendMode;

};

