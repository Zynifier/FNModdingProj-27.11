// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "GameplayTagContainer.h"
#include "BlueprintContextBase.h"
#include "FortUIDataConfigurationContext.generated.h"

class UFortMobileHUDLayoutToolV2;
class UUserWidget;
enum class EFortItemType : uint8;

UCLASS()
class FORTNITEUI_API UFortUIDataConfigurationContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool ArePartyFeaturesEnabled() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool AreSocialFeaturesEnabled() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	FPostProcessSettings GetFrontEndFFSettings() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	TSoftClassPtr<UFortMobileHUDLayoutToolV2> GetHUDLayoutToolV2SoftClass() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	TArray<EFortItemType> GetItemTypesToUseVaultCamera() const;

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<UUserWidget> GetSoftWidgetClassForAlias(const FGameplayTag& WidgetAlias) const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool IsChatEnabled() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool IsLimitedToES2Features() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool IsQuestVOEnabled() const;

	UFUNCTION(BlueprintPure, Category="UIDataConfiguration")
	bool UseSpecificPinataWeapon() const;

};

