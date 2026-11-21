// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DadBroHealthInterface.generated.h"

enum class EDadBroHealthType : uint8;

UENUM(BlueprintType)
enum class EDadBroHealthType : uint8
{
	None = 0,
	// health percent should be cumulative (.75 for two full points and a damaged one)

	Weakpoints = 1,
	// health percent is the horn's health

	Horn = 2,
	// boss health

	Guy = 3,
};

UINTERFACE(MinimalAPI)
class UDadBroHealthInterface : public UInterface
{
	GENERATED_BODY()
};

class IDadBroHealthInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="DadBroHealth")
	float GetCurrentHealthPercent() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="DadBroHealth")
	EDadBroHealthType GetCurrentHealthType() const;

};

