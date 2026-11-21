// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLevelScriptActor.h"
#include "FortFrontendLevelScriptActor.generated.h"

class AFortFrontendLevelScriptActor;
class AFortItemPreviewPedestal;
class UObject;

UCLASS(HideCategories=("Collision", "Rendering", "Transformation"), meta=(ScriptName="FortFrontendLevelScriptActor"))
class AFortFrontendLevelScriptActor : public AFortLevelScriptActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<AFortItemPreviewPedestal> GetCommanderPreviewPedestalActor() const;

	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static AFortFrontendLevelScriptActor* GetFrontendLevelScript(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<AFortItemPreviewPedestal> GetHeroLoadoutPreviewPedestalActor() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Commander Room")
	TSoftObjectPtr<AFortItemPreviewPedestal> CommanderPreviewPedestalActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hero Loadout")
	TSoftObjectPtr<AFortItemPreviewPedestal> HeroLoadoutPreviewPedestalActor;

};

