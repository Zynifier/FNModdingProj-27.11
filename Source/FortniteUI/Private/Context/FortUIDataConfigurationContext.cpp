// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortUIDataConfigurationContext.h"

bool UFortUIDataConfigurationContext::ArePartyFeaturesEnabled() const
{
	return false;
}

bool UFortUIDataConfigurationContext::AreSocialFeaturesEnabled() const
{
	return false;
}

FPostProcessSettings UFortUIDataConfigurationContext::GetFrontEndFFSettings() const
{
	return FPostProcessSettings();
}

TSoftClassPtr<UFortMobileHUDLayoutToolV2> UFortUIDataConfigurationContext::GetHUDLayoutToolV2SoftClass() const
{
	return TSoftClassPtr<UFortMobileHUDLayoutToolV2>();
}

TArray<EFortItemType> UFortUIDataConfigurationContext::GetItemTypesToUseVaultCamera() const
{
	return TArray<EFortItemType>();
}

TSoftClassPtr<UUserWidget> UFortUIDataConfigurationContext::GetSoftWidgetClassForAlias(const FGameplayTag& WidgetAlias) const
{
	return TSoftClassPtr<UUserWidget>();
}

bool UFortUIDataConfigurationContext::IsChatEnabled() const
{
	return false;
}

bool UFortUIDataConfigurationContext::IsLimitedToES2Features() const
{
	return false;
}

bool UFortUIDataConfigurationContext::IsQuestVOEnabled() const
{
	return false;
}

bool UFortUIDataConfigurationContext::UseSpecificPinataWeapon() const
{
	return false;
}
