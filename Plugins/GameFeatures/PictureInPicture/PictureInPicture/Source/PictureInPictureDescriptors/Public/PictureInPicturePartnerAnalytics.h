// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PictureInPicturePartnerData.h"
#include "PictureInPicturePartnerAnalytics.generated.h"

USTRUCT(BlueprintType)
struct PICTUREINPICTUREDESCRIPTORS_API FPictureInPictureAnalyticsPayload
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<PictureInPictureAction, int32> PartnerActionTally;

};

UCLASS()
class PICTUREINPICTUREDESCRIPTORS_API UPictureInPictureAnalyticsManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FString, FPictureInPictureAnalyticsPayload> PartnerAnalytics;

};

