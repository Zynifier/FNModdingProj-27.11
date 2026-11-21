// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_SpeechBubble.generated.h"

class UDataTable;
class UFortPawnComponent_AIGroup;
class UWidgetComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpeechBubbleHideEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpeechBubbleShowEvent);

USTRUCT()
struct FFortSpeechBubbleDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpeechBubble")
	bool bEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpeechBubble")
	FText SpeechBubbleText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpeechBubble")
	FGameplayTagContainer FilterTags;

};

USTRUCT()
struct FFortSpeechBubbleInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 bIsSpeaking : 1;

	UPROPERTY(Transient)
	uint8 bIsValidSelectedText : 1;

	UPROPERTY(Transient)
	uint8 SelectedTextIndex;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_SpeechBubble : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Speech Bubble")
	const FText& GetSpeechBubbleText() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Speech Bubble")
	void StartSpeech(const FGameplayTagQuery FilterTagQuery);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Speech Bubble")
	void StopSpeech();

	UPROPERTY(BlueprintAssignable)
	FSpeechBubbleShowEvent SpeechBubbleShow;

	UPROPERTY(BlueprintAssignable)
	FSpeechBubbleHideEvent SpeechBubbleHide;

private:
	UFUNCTION()
	void OnRep_SpeechBubbleInfo();

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UDataTable> SpeechBubbleTexts;

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UWidgetComponent> SpeechBubbleWidgetComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseRandomTextAtEachSpeech;

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	FScalableFloat DisplayBubbleDuration;

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpeechBubbleMaxDrawDistance;

	UPROPERTY(EditDefaultsOnly, Category="Speech Bubble", meta=(AllowPrivateAccess="true"))
	FScalableFloat CheckGroupMembersToSpeak;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SpeechBubbleInfo)
	FFortSpeechBubbleInfo SpeechBubbleInfo;

	UPROPERTY(Transient)
	FText CachedSelectedText;

	UPROPERTY(Transient)
	float SpeechBubbleMaxDrawDistanceSqr;

	UPROPERTY(Transient)
	bool bIsLocalPlayerWithinSpeechBubbleDrawDistance;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidgetComponent> TextWidgetComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_AIGroup> CachedGroupComponent;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> LoadedTextsDataTable;

};

