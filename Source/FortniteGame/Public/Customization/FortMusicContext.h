// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "BlueprintContextBase.h"
#include "FortMusicContext.generated.h"

class UAthenaMusicPackItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActiveMusicPackChangedDelegate, const UAthenaMusicPackItemDefinition*, NewMusicPack, float, StartTimeOffset);

UCLASS(MinimalAPI)
class UFortMusicContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UAthenaMusicPackItemDefinition* GetEquippedMusicPack();

	UFUNCTION(BlueprintCallable)
	bool IsDefaultMusicEquipped();

	UFUNCTION(BlueprintCallable)
	void SetActiveMusicPack(const UAthenaMusicPackItemDefinition* NewMusicPack, float StartTimeOffset = 0.000000f);

	UPROPERTY(BlueprintAssignable, Category="Cosmetics")
	FActiveMusicPackChangedDelegate OnMusicPackChanged;

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaMusicPackItemDefinition> DesiredActiveMusicPack;

	UPROPERTY(Transient)
	TArray<FPrimaryAssetId> LoadedPacks;

};

