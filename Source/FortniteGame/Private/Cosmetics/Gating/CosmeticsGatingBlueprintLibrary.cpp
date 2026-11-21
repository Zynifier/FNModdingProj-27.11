// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Gating/CosmeticsGatingBlueprintLibrary.h"

void UFortCosmeticsGatingBlueprintLibrary::ConvertCosmeticItemDefinitionsToInterfaces(const TArray<UAthenaCosmeticItemDefinition*>& CosmeticItemDefinitions, TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OutCosmeticItemGatingInterfaces)
{
}

TScriptInterface<ICosmeticItemGatingInterface> UFortCosmeticsGatingBlueprintLibrary::ConvertCosmeticItemDefinitionToInterface(const UAthenaCosmeticItemDefinition* CosmeticItemDefinition)
{
	return TScriptInterface<ICosmeticItemGatingInterface>();
}

void UFortCosmeticsGatingBlueprintLibrary::ConvertItemQuantityPairsToCosmeticGatingInterfaces(const TArray<FFortItemQuantityPair>& InItemQuantityPairs, TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OutCosmeticItemGatingInterfaces)
{
}

void UFortCosmeticsGatingBlueprintLibrary::GetAgeRatingIconsForExperiences(ULocalPlayer* LocalPlayer, TArray<UTexture2DDynamic*>& AgeRatingIconsForExperiences)
{
}

void UFortCosmeticsGatingBlueprintLibrary::GetCosmeticGatingDisplayData(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& OfferScriptInterface, FAgeRatingDisplayData& OutageRatingDisplayData)
{
}

FText UFortCosmeticsGatingBlueprintLibrary::GetLobbyGatingMessage(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& CurrentEquippedCosmetics)
{
	return FText();
}

FText UFortCosmeticsGatingBlueprintLibrary::GetLockerGatingMessage(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& CosmeticItemGatingInterface)
{
	return FText();
}

FText UFortCosmeticsGatingBlueprintLibrary::GetOfferNextLowerRatingRestrictionText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferGrantedCosmetics)
{
	return FText();
}

FText UFortCosmeticsGatingBlueprintLibrary::GetOfferRatingRestrictionText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferGrantedCosmetics)
{
	return FText();
}

FText UFortCosmeticsGatingBlueprintLibrary::GetPurchaseConfirmationRatingRestrictedWarningText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferItems, const bool bIsRatingSettingBelowRatingCap)
{
	return FText();
}

bool UFortCosmeticsGatingBlueprintLibrary::HasRatingRestrictions(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& CosmeticItemGatingInterface)
{
	return false;
}

bool UFortCosmeticsGatingBlueprintLibrary::IsContentGatingEnabled()
{
	return false;
}

bool UFortCosmeticsGatingBlueprintLibrary::IsPlayerRatingRestricted(ULocalPlayer* LocalPlayer)
{
	return false;
}

bool UFortCosmeticsGatingBlueprintLibrary::IsRatingSettingBelowRatingCap(ULocalPlayer* LocalPlayer)
{
	return false;
}

bool UFortCosmeticsGatingBlueprintLibrary::ShouldBeGatedByAgeRating(ULocalPlayer* InLocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& InCosmeticItemGatingInterface)
{
	return false;
}
