// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LiveLinkRetargetAsset.h"
#include "FacialLiveLinkRemapAsset.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFacialLiveLinkRemapAsset : public ULiveLinkRetargetAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UFacialLiveLinkRemapAsset")
	bool bExtractBoneTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UFacialLiveLinkRemapAsset")
	bool bExtractCurve;

};

