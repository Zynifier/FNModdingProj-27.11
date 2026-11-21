// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEventName.generated.h"

UENUM()
enum class EFortEventNameType : uint8
{
	// Mission events, valid on server

	Mission = 0,
	// Client events, valid on clients

	Client = 1,
};

USTRUCT()
struct FFortEventName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventName")
	FName CategoryName;

	UPROPERTY(EditAnywhere, Category="EventName")
	FName EventName;

};

USTRUCT(BlueprintType)
struct FFortClientEventName : public FFortEventName
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortMissionEventName : public FFortEventName
{
	GENERATED_BODY()

};

