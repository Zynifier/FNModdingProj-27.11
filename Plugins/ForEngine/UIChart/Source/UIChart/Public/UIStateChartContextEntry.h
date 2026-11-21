// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartContextEntry.generated.h"

class ULocalPlayer;

USTRUCT()
struct UICHART_API FUIStateChartContextEntryOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OverrideValue;

};

UCLASS(BlueprintType)
class UICHART_API UUIStateChartContextEntry : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetCommonValueAsBool() const;

	UFUNCTION(BlueprintPure)
	float GetCommonValueAsFloat() const;

	UFUNCTION(BlueprintPure)
	int32 GetCommonValueAsInt() const;

	UFUNCTION(BlueprintPure)
	FString GetCommonValueAsString() const;

	UFUNCTION(BlueprintPure)
	bool GetPlayerValueAsBool(const ULocalPlayer* InLocalPlayer) const;

	UFUNCTION(BlueprintPure)
	float GetPlayerValueAsFloat(const ULocalPlayer* InLocalPlayer) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerValueAsInt(const ULocalPlayer* InLocalPlayer) const;

	UFUNCTION(BlueprintPure)
	FString GetPlayerValueAsString(const ULocalPlayer* InLocalPlayer) const;

	UFUNCTION(BlueprintPure)
	bool IsEmptyForPlayer(ULocalPlayer* InLocalPlayer = nullptr) const;

protected:
	UPROPERTY()
	FString CommonValue;

	UPROPERTY()
	TMap<ULocalPlayer*, FUIStateChartContextEntryOverride> PlayerOverrides;

};

