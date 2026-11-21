// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "UObject/PrimaryAssetId.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_ExternalEmote.generated.h"

class UInputComponent;
class UUserWidget;

USTRUCT(BlueprintType)
struct FEmoteActionBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EmoteActionBinding")
	FPrimaryAssetId EmoteId;

	UPROPERTY(EditAnywhere, Category="EmoteActionBinding")
	bool bOnlyDisplayForDiscoverability;

	UPROPERTY(EditAnywhere, Category="EmoteActionBinding")
	FName ActionName;

	UPROPERTY(EditAnywhere, Category="EmoteActionBinding")
	TArray<FInputActionKeyMapping> Input;

};

USTRUCT(BlueprintType)
struct FExternalEmoteCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	FName CategoryName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	FText CategoryTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	FText CategoryTitleMultipage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	TArray<FEmoteActionBinding> Emotes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	uint8 bExclusive : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	uint8 bForceUIFocusWhenAdded : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalEmoteCategory")
	TSubclassOf<UUserWidget> OverlayWidgetClass;

};

USTRUCT(BlueprintType)
struct FExternalMultiEmote
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmote")
	TArray<FEmoteActionBinding> Emotes;

};

USTRUCT(BlueprintType)
struct FExternalMultiEmoteCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	FName CategoryName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	FText CategoryTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	FText CategoryTitleMultipage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	TArray<FExternalMultiEmote> Emotes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	uint8 bExclusive : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	uint8 bForceUIFocusWhenAdded : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExternalMultiEmoteCategory")
	TSubclassOf<UUserWidget> OverlayWidgetClass;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ExternalEmote : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddExternalEmoteCategories(const TArray<FExternalEmoteCategory>& NewCategories, const bool bAllowMerging = false, const bool bAllowUnownedEmotes = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddExternalEmotes(const TArray<FEmoteActionBinding>& NewEmotes, const bool bAllowUnownedEmotes = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddExternalEmoteSimple(const FPrimaryAssetId& Emote, const bool bAllowUnownedEmotes = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddExternalMultiEmoteCategories(const TArray<FExternalMultiEmoteCategory>& NewCategories);

	UFUNCTION(BlueprintPure)
	const TArray<FExternalEmoteCategory>& GetExternalEmotes() const;

	UFUNCTION(BlueprintPure)
	const TArray<FExternalMultiEmoteCategory>& GetExternalMultiEmotes() const;

	UFUNCTION(BlueprintPure)
	const TArray<FEmoteActionBinding>& GetUncategorizedEmotes() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveExternalEmote(const FPrimaryAssetId& EmoteToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveExternalEmoteByActionBinding(const FEmoteActionBinding& EmoteToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveExternalEmoteCategories(const TArray<FName>& CategoriesToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(DisplayName="RemoveExternalEmotesByAssetId"))
	void RemoveExternalEmotes(const TArray<FPrimaryAssetId>& EmotesToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveExternalEmotesByActionBinding(const TArray<FEmoteActionBinding>& EmotesToRemove);

protected:
	UFUNCTION()
	void OnRep_ExternalEmotes(TArray<FExternalEmoteCategory>& PreviousExternalEmotes);

	UFUNCTION()
	void OnRep_ExternalMultiEmotes(TArray<FExternalMultiEmoteCategory>& PreviousExternalMultiEmotes);

	UFUNCTION()
	void OnRep_UncategorizedEmotes(TArray<FEmoteActionBinding>& PreviousUncategorizedEmotes);

	UFUNCTION()
	void PlayEmoteAtIndex(const int32 CategoryIndex, const int32 EmoteIndex);

	UFUNCTION()
	void PlayUncategorizedEmoteAtIndex(const int32 EmoteIndex);

	UPROPERTY(ReplicatedUsing=OnRep_ExternalEmotes)
	TArray<FExternalEmoteCategory> ExternalEmotes;

	UPROPERTY(ReplicatedUsing=OnRep_ExternalMultiEmotes)
	TArray<FExternalMultiEmoteCategory> ExternalMultiEmotes;

	UPROPERTY(ReplicatedUsing=OnRep_UncategorizedEmotes)
	TArray<FEmoteActionBinding> UncategorizedEmotes;

	UPROPERTY(Transient)
	TArray<FName> PlayedActions;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InputComponent;

};

