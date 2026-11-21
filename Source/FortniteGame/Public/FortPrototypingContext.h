// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortPrototypingContext.generated.h"

enum class EFortPrototypingStatus : uint8;

UENUM(BlueprintType)
enum class EFortPrototypingStatus : uint8
{
	Unknown = 0,
	Disabled = 1,
	Enabled = 2,
};

UCLASS()
class UFortPrototypingContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPrototypingStatusChanged);

public:
	UFUNCTION(BlueprintPure, Category="Prototyping")
	EFortPrototypingStatus GetPrototypingStatus() const;

	UPROPERTY(BlueprintAssignable, Category="Prototyping")
	FOnPrototypingStatusChanged OnPrototypingStatusChangedEvent;

private:
	UFUNCTION()
	void HandleMcpProfilesInitialized();

};

