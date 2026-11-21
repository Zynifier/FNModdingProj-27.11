// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortAbilityDecoTool.h"
#include "FortCustomizableAbilityDecoTool.generated.h"

class AFortDecoHelper;
class AFortWeapon;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortCustomizableAbilityDecoTool : public AFortAbilityDecoTool
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnEquip"))
	void BPOnEquip(AFortWeapon* OldWeapon);

	UFUNCTION(BlueprintImplementableEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnSetPreview"))
	void BPOnSetDecoObjectPreview(AFortDecoHelper* FortDecoHelper);

	UFUNCTION(BlueprintImplementableEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnUnEquip"))
	void BPOnUnEquip();

	UFUNCTION(BlueprintNativeEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnPressSecondaryFire"))
	void BPPressSecondaryFire(AFortDecoHelper* FortDecoHelper);

	UFUNCTION(BlueprintNativeEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnPressTrigger"))
	void BPPressTrigger(AFortDecoHelper* FortDecoHelper);

	UFUNCTION(BlueprintNativeEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnReleaseSecondaryFire"))
	void BPReleaseSecondaryFire(AFortDecoHelper* FortDecoHelper);

	UFUNCTION(BlueprintNativeEvent, Category="DecoTool", meta=(BlueprintProtected, DisplayName="OnReleaseTrigger"))
	void BPReleaseTrigger(AFortDecoHelper* FortDecoHelper);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Ability")
	void BPServerPressSecondaryFire();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Ability")
	void BPServerReleaseSecondaryFire();

	UFUNCTION(BlueprintCallable, Category="AbilityDecoTool")
	void ExecuteDecoAbility();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPressSecondaryFire();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Ability")
	void ServerPressTrigger();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReleaseSecondaryFire();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, BlueprintCosmetic, Category="Ability")
	void ServerReleaseTrigger();

protected:
	UPROPERTY(EditDefaultsOnly, Category="AbilityDecoTool")
	bool bExecuteToolAbilityOnPress;

};

