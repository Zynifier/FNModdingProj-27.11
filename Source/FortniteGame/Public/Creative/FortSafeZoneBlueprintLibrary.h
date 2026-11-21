// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortSafeZoneBlueprintLibrary.generated.h"

class APlayerState;
class IFortSafeZoneInterface;
class UObject;

UCLASS()
class UFortSafeZoneBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="Safe Zone Interface", meta=(WorldContext="WorldContextObject"))
	static TScriptInterface<IFortSafeZoneInterface> GetGlobalSafeZoneInterface(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Safe Zone Interface")
	static TScriptInterface<IFortSafeZoneInterface> GetRelevantSafeZoneInterface(APlayerState* PlayerContext);

	UFUNCTION(BlueprintPure, Category="Safe Zone Interface")
	static FVector GetSafeZoneNextCenter(const TScriptInterface<IFortSafeZoneInterface>& InSafeZoneInterface);

	UFUNCTION(BlueprintPure, Category="Safe Zone Interface")
	static FVector GetSafeZoneNextNextCenter(const TScriptInterface<IFortSafeZoneInterface>& InSafeZoneInterface);

};

