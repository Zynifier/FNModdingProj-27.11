// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorLabelOverride.generated.h"

class APlayerController;

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortActorLabelOverrideInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortActorLabelOverrideInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual bool CanOverrideLabel() const;

	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual FText GetBaseLabel() const;

	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual FText GetDisplayLabel() const;

	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual FString GetLabelOverride() const;

	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual bool ResetLabelOverride(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="LabelOverride")
	virtual bool SetLabelOverride(APlayerController* PlayerController, const FString& NewLabelOverride);

};

