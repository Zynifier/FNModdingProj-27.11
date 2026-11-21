// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInteractInterface.h"
#include "FortInterface_OverrideCanInteract.generated.h"

class IFortInteractInterface;
class UFortControllerComponent_Interaction;

UINTERFACE(BlueprintType)
class UFortInterface_OverrideCanInteract : public UInterface
{
	GENERATED_BODY()
};

class IFortInterface_OverrideCanInteract
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	bool ShouldOverrideCanInteract(bool& bOutCanInteract, const UFortControllerComponent_Interaction* PCInteractionComponent, const TScriptInterface<IFortInteractInterface>& ObjectBeingInteractedWithInterface, const FInteractionType& InteractionType) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	bool ShouldSuppressDisplayInteraction(const UFortControllerComponent_Interaction* PCInteractionComponent, const TScriptInterface<IFortInteractInterface>& ObjectBeingInteractedWithInterface, const FInteractionType& InteractionType) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interaction")
	bool ShouldSuppressInteractionWidget(const UFortControllerComponent_Interaction* PCInteractionComponent, const TScriptInterface<IFortInteractInterface>& ObjectBeingInteractedWithInterface, const FInteractionType& InteractionType) const;

};

