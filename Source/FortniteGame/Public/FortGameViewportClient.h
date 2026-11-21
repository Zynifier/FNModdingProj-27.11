// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameViewportClient.h"
#include "FortGameViewportClient.generated.h"

UCLASS(MinimalAPI)
class UFortGameViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void SetViewportSize(int32 ControllerId, float OriginX, float OriginY, float SizeX, float SizeY, const float Time = 0.300000f);

private:
	UPROPERTY(Transient)
	FText NetworkFailureMessage;

	UPROPERTY(Transient)
	FString NetworkFailureMessageAdditionalAnalyticsString;

};

