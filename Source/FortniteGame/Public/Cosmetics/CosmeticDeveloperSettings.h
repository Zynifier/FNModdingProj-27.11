// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "CosmeticDeveloperSettings.generated.h"

class UAthenaCosmeticItemDefinition;
class UCustomCharacterPart;
class UFortVariantTokenType;

UCLASS(Config=EditorPerProjectUserSettings, MinimalAPI, meta=(DisplayName="Cosmetic Cheats"))
class UCosmeticDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HandleCosmeticLoadoutOverridesChanged();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Cosmetics")
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CosmeticItemOverrides;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Cosmetics")
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CosmeticItemsToPreRegister;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Cosmetics", meta=(ShowOnlyInnerProperties="TRUE"))
	FFortAthenaLoadout CosmeticLoadoutOverrides;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Cosmetics")
	TObjectPtr<UFortVariantTokenType> VariantTokenToPreview;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CosmeticItemsToDeny;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterPartsToDeny;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	FGameplayTagContainer ActiveCosmeticTagsToFake;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	bool bAllowAccessToAllEmotesForTesting;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	bool bHighPriorityCosmeticsCheats;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	bool bRequireEmoteOwnershipInPIE;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="CosmeticItemAccess")
	bool bForcedMontageAccess;
#endif

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Cosmetics")
	bool bAllowAccessToHeroOutfitsAndBackblingForTesting;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Transient, AdvancedDisplay, Category="Cosmetics")
	bool bRequireSprayOwnershipInPIE;
#endif

	UPROPERTY(EditAnywhere, Config, Transient, AdvancedDisplay, Category="Cosmetics")
	uint8 bAllowAccessToAllSprayVariantsForFrontEndTesting : 1;

	UPROPERTY(EditAnywhere, Config, Transient, AdvancedDisplay, Category="Cosmetics")
	uint8 bAllowAccessToAllEmojiVariantsForFrontEndTesting : 1;

	UPROPERTY(EditAnywhere, Config, Transient, AdvancedDisplay, Category="Cosmetics")
	uint8 bAllowAccessToAllWrapVariantsForFrontEndTesting : 1;

};

