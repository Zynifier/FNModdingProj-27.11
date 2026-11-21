// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticStep.h"
#include "Customization/FortCustomizationAssetLoader.h"
#include "FortCosmeticStep_AwaitLoadRequest.generated.h"

USTRUCT()
struct FFortCosmeticStep_AwaitLoadRequestPayload : public FFortCustomizationAssetsToLoadSourceInterface
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticStep_AwaitLoadRequest : public UFortCosmeticStep
{
	GENERATED_BODY()

};

