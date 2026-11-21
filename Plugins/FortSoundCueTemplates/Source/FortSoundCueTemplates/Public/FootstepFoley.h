// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerFoley.h"
#include "FootstepFoley.generated.h"

UCLASS(BlueprintType, HideCategories=("object", "object", "object", "Object"), meta=(DisplayName="Footstep Foley"))
class FORTSOUNDCUETEMPLATES_API UFootstepFoley : public UPlayerFoley
{
	GENERATED_BODY()

public:
	UFootstepFoley(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual FString GenerateDefaultNewAssetName(const TArray<TWeakObjectPtr<USoundWave>>& Waves) const override;

private:
	void PopulateStepTypes();
#endif

#if WITH_EDITORONLY_DATA
private:
	TArray<FString> StepTypes;
#endif

};

