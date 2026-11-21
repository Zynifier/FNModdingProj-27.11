// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PortamentoSettings.generated.h"

UENUM()
enum class EPortamentoMode : uint8
{
	Legato = 0 UMETA(Json="legato"),
	Persistent = 1 UMETA(Json="persistent"),
	Num = 2 UMETA(Hidden),
	None = 3 UMETA(Hidden),
};

USTRUCT()
struct FPortamentoSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EPortamentoMode Mode;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", UIMax="10", UIMin="0"))
	float Seconds;

};

