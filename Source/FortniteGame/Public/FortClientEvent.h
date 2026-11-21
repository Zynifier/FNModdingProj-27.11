// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientEvent.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFortClientEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClientEvent")
	FName CategoryName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClientEvent")
	FName EventName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClientEvent")
	TObjectPtr<UObject> EventSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClientEvent")
	TObjectPtr<UObject> EventFocus;

};

