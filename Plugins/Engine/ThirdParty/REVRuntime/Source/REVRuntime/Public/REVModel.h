// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "REVModel.generated.h"

class UAssetImportData;

/**
 * Asset that loads a rev model and spawns an FREVGenerator
 */
UCLASS(BlueprintType)
class REVRUNTIME_API UREVModel : public UObject
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Instanced, Category="ImportSettings")
	TObjectPtr<UAssetImportData> AssetImportData;
#endif

#if WITH_EDITORONLY_DATA
	// Size in Kilobytes of imported REV model

	UPROPERTY(VisibleAnywhere, Category="Model")
	int32 AssetSizeKB;
#endif

private:
	// SampleRate of the imported REV model

	UPROPERTY(VisibleAnywhere, Category="Model")
	float SampleRate;

	// number of channels in the imported REV model

	UPROPERTY(VisibleAnywhere, Category="Model")
	int32 NumChannels;

};

