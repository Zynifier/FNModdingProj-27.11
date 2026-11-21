// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "FortCombatTypes.h"
#include "FortAnimNotify_PlayReloadFX.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Play Reload FX"))
class UFortAnimNotify_PlayReloadFX : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reload FX")
	TEnumAsByte<EFortReloadFXState::Type> ReloadStage;

private:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Reload FX")
	void SetReloadStage(EFortReloadFXState::Type InReloadStage) const;

};

