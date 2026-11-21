// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortItemQuantityPair.h"
#include "FortRatingDataManager.h"
#include "CosmeticsGatingBlueprintLibrary.generated.h"

class ICosmeticItemGatingInterface;
class UAthenaCosmeticItemDefinition;
class ULocalPlayer;
class UTexture2DDynamic;

UCLASS(MinimalAPI)
class UFortCosmeticsGatingBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void ConvertCosmeticItemDefinitionsToInterfaces(const TArray<UAthenaCosmeticItemDefinition*>& CosmeticItemDefinitions, TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OutCosmeticItemGatingInterfaces);

	UFUNCTION(BlueprintCallable)
	static TScriptInterface<ICosmeticItemGatingInterface> ConvertCosmeticItemDefinitionToInterface(const UAthenaCosmeticItemDefinition* CosmeticItemDefinition);

	UFUNCTION(BlueprintCallable)
	static void ConvertItemQuantityPairsToCosmeticGatingInterfaces(const TArray<FFortItemQuantityPair>& InItemQuantityPairs, TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OutCosmeticItemGatingInterfaces);

	UFUNCTION(BlueprintCallable)
	static void GetAgeRatingIconsForExperiences(ULocalPlayer* LocalPlayer, TArray<UTexture2DDynamic*>& AgeRatingIconsForExperiences);

	UFUNCTION(BlueprintCallable)
	static void GetCosmeticGatingDisplayData(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& OfferScriptInterface, FAgeRatingDisplayData& OutageRatingDisplayData);

	UFUNCTION(BlueprintCallable)
	static FText GetLobbyGatingMessage(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& CurrentEquippedCosmetics);

	UFUNCTION(BlueprintCallable)
	static FText GetLockerGatingMessage(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& CosmeticItemGatingInterface);

	UFUNCTION(BlueprintCallable)
	static FText GetOfferNextLowerRatingRestrictionText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferGrantedCosmetics);

	UFUNCTION(BlueprintCallable)
	static FText GetOfferRatingRestrictionText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferGrantedCosmetics);

	UFUNCTION(BlueprintCallable)
	static FText GetPurchaseConfirmationRatingRestrictedWarningText(ULocalPlayer* LocalPlayer, const TArray<TScriptInterface<ICosmeticItemGatingInterface>>& OfferItems, const bool bIsRatingSettingBelowRatingCap);

	UFUNCTION(BlueprintCallable)
	static bool HasRatingRestrictions(ULocalPlayer* LocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& CosmeticItemGatingInterface);

	UFUNCTION(BlueprintPure)
	static bool IsContentGatingEnabled();

	UFUNCTION(BlueprintPure)
	static bool IsPlayerRatingRestricted(ULocalPlayer* LocalPlayer);

	UFUNCTION(BlueprintPure)
	static bool IsRatingSettingBelowRatingCap(ULocalPlayer* LocalPlayer);

	UFUNCTION(BlueprintCallable)
	static bool ShouldBeGatedByAgeRating(ULocalPlayer* InLocalPlayer, const TScriptInterface<ICosmeticItemGatingInterface>& InCosmeticItemGatingInterface);

};

