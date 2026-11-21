// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpCatalogEnums.h"
#include "FortMtxWallets.generated.h"

enum class EAppStore : uint8;

UENUM()
enum class EFortMtxPlatform : uint8
{
	/** Mtx that was purchased on an Epic platform */
	Epic = 0,
	/** Mtx that was purchased on PlayStation4 or PlayStation5 */
	PSN = 1,
	/** Mtx that was purchased on XboxOne or Xbox Series */
	Live = 2,
	/** Mtx that was not purchased */
	Shared = 3,
	/** Mtx that was purchased on PC (Worldwide) */
	EpicPC = 4,
	/** Mtx that was purchased on PC in Korea */
	EpicPCKorea = 5,
	/** Mtx that was purchased on IOS */
	IOSAppStore = 6,
	/** Mtx that was purchased on Android through the Epic storefront */
	EpicAndroid = 7,
	/** Mtx that was purchased on Nintendo platforms */
	Nintendo = 8,
	/** Mtx that was purchased on WeGame */
	WeGame = 9,
	/** Mtx that was purchased on Samsung devices */
	Samsung = 10,
	/** Mtx that was purchased on Android through the Google Play App Store */
	GooglePlay = 11,
};

USTRUCT()
struct FFortMtxPlatformList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<EFortMtxPlatform> MtxPlatformList;

};

UCLASS(Config=Game, MinimalAPI)
class UFortMtxWallets : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Real Money Store")
	static TArray<EAppStore> GetAvailableAppStores();

	UFUNCTION(BlueprintPure, Category="Real Money Store")
	static bool GetSelectedAppStore(EAppStore& OutAppStore);

	UFUNCTION(BlueprintCallable, Category="Real Money Store")
	static void SetSelectedAppStore(const EAppStore InAppStore);

protected:
	UPROPERTY(Config)
	TMap<EFortMtxPlatform, FFortMtxPlatformList> SharedWallets;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Config)
	TMap<EAppStore, FFortMtxPlatformList> AppStoreMtxPlatformMappings;
#endif

};

