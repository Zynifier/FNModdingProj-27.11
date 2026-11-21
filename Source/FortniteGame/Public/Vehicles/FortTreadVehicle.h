// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortTreadVehicle.generated.h"

class UFortTreadVehicleConfigs;

UENUM(BlueprintType)
namespace ETreadSide
{
	enum Type
	{
		Invalid = 0,
		Left = 1,
		Right = 2,
	};
}

UENUM(BlueprintType)
namespace EVelocityUnits
{
	enum Type
	{
		CentimetersPerSecond = 0,
		KilometersPerHour = 1,
	};
}

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortTreadVehicle : public AFortAthenaVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API float GetTreadCompression() const;

	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API bool GetTreadContactPoints(TArray<FVector>& OutTreadContactPoints, const ETreadSide::Type TreadSide = ETreadSide::Invalid, const bool bIncludeMisses = true, const bool bOrdered = false) const;

	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API float GetTreadPower(const ETreadSide::Type Side, const bool bClamp = true) const;

	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API float GetTreadVelocity(const ETreadSide::Type Side, const EVelocityUnits::Type Units = EVelocityUnits::KilometersPerHour) const;

	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API bool IsLeftTreadEnabled() const;

	UFUNCTION(BlueprintPure, Category="Tread Vehicle")
	FORTNITEGAME_API bool IsRightTreadEnabled() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Tread Vehicle")
	FORTNITEGAME_API void OnTreadCompressed(const FHitResult HitResult, const float Compression, const float CompressionVelocity);

	UFUNCTION(BlueprintImplementableEvent, Category="Tread Vehicle")
	FORTNITEGAME_API void OnTreadDecompressed(const FHitResult HitResult, const float Compression, const float CompressionVelocity);

	UFUNCTION(BlueprintImplementableEvent, Category="Tread Vehicle")
	FORTNITEGAME_API void OnTreadEnabled(const bool bEnabled, const ETreadSide::Type Side);

	UFUNCTION(BlueprintCallable, Category="Tread Vehicle")
	FORTNITEGAME_API void SetLeftTreadEnabled(const bool bNewValue);

	UFUNCTION(BlueprintCallable, Category="Tread Vehicle")
	FORTNITEGAME_API void SetRightTreadEnabled(const bool bNewValue);

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TSubclassOf<UFortTreadVehicleConfigs> ConfigsClass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortTreadVehicleConfigs> FortTreadVehicleConfigs;

protected:
	UPROPERTY(Transient)
	bool bLeftTreadEnabled;

	UPROPERTY(Transient)
	bool bRightTreadEnabled;

};

