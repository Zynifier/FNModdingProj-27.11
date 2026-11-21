// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortEventName.h"
#include "FortClientEventData.generated.h"

UCLASS(MinimalAPI)
class UFortClientEventData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ClientEvent")
	TArray<FFortClientEventName> ClientEventNames;

};

