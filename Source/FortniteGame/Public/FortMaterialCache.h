// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PerPlatformProperties.h"
#include "UObject/NoExportTypes.h"
#include "FortMaterialCache.generated.h"

class UFortMaterialCache;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;

USTRUCT(BlueprintType)
struct FMaterialCacheSettings : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MaterialCacheSettings")
	int32 bDisable;

	UPROPERTY(EditAnywhere, Category="MaterialCacheSettings")
	FPerPlatformInt PlatformMaxCount;

};

USTRUCT()
struct FMaterialReservation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstance;

};

UCLASS(BlueprintType)
class UFortMaterialCache : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ReleaseMaterial(UPARAM(ref) UMaterialInstanceDynamic*& MaterialInstance);

	UFUNCTION(BlueprintCallable)
	bool ReserveMaterial(UMaterialInstanceDynamic*& OutMaterialInstance);

private:
	UPROPERTY(Transient)
	TArray<FMaterialReservation> Reservations;

};

UCLASS(BlueprintType)
class UFortMaterialCacheManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static UFortMaterialCache* GetCache(UObject* WorldContextObject, const FDataTableRowHandle& CacheSettings, UMaterialInterface* BaseMaterial);

};

