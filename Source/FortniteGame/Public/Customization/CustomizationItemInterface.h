// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "CustomizationItemInterface.generated.h"

class UAthenaCosmeticItemDefinition;
class USceneComponent;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UCustomizationItemInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ICustomizationItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Customization")
	virtual UAthenaCosmeticItemDefinition* GetCustomizationCosmeticItem() const;

	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual USceneComponent* GetCustomizationItemRotatableSceneComponent() const;

	UFUNCTION(BlueprintCallable, Category="Customization")
	virtual void ResetCustomizationCosmeticItemAndVariants(UAthenaCosmeticItemDefinition* NewCosmeticItemDefinition, const TArray<FMcpVariantChannelInfo>& InOverrideVariants);

	UFUNCTION(BlueprintCallable, Category="Customization")
	virtual void SetCustomizationCosmeticItemAndVariants(UAthenaCosmeticItemDefinition* NewCosmeticItemDefinition, const TArray<FMcpVariantChannelInfo>& InOverrideVariants);

};

