// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "FortActivityBrowserColorSchemeAsset.generated.h"

class UMaterialParameterCollection;

USTRUCT(BlueprintType)
struct FColorSchemeParamaterValues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSchemeParamaterValues")
	TObjectPtr<UMaterialParameterCollection> AlternateMaterialCollection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSchemeParamaterValues", meta=(EditFixedOrder))
	TMap<FName, float> ScalarParameterValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSchemeParamaterValues", meta=(EditFixedOrder))
	TMap<FName, FLinearColor> VectorParameterValues;

};

UCLASS(BlueprintType)
class UFortActivityBrowserColorSchemeAsset : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActivityBrowserColorSchemeAsset")
	TMap<TObjectPtr<UMaterialParameterCollection>, FColorSchemeParamaterValues> MaterialCollectionOverrides;

};

