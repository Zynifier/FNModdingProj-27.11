// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationContext.h"
#include "ConversationTaskNode.h"
#include "ConversationTypes.h"
#include "GameplayTagContainer.h"
#include "FortConversationTaskNode.generated.h"

class UCommonActivatableWidget;
class UObject;
class USoundBase;
class UUserWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortConversationTaskNode : public UConversationTaskNode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual TSoftObjectPtr<USoundBase> GetChoiceSound() const;

	UFUNCTION(BlueprintNativeEvent)
	TSoftObjectPtr<UObject> GetDisplayAssetForChoice(const FConversationContext& Context, const FClientConversationOptionEntry& InOptionEntry) const;

	UFUNCTION(BlueprintPure)
	virtual TSoftObjectPtr<USoundBase> GetHoverChoiceSound() const;

	UFUNCTION(BlueprintPure)
	virtual TSoftObjectPtr<UObject> GetTaskIcon() const;

	UPROPERTY(EditDefaultsOnly, Category="Categorization")
	FGameplayTagContainer NodeTags;

	UPROPERTY(EditDefaultsOnly, Category="Categorization")
	FString NodeType;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void OnPreviewedChoicePickedByUser(const FConversationContext& Context, const FClientConversationOptionEntry& ClientChoice) const;

	UPROPERTY(EditDefaultsOnly, Category="UI", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface,/Script/Engine.DataAsset"))
	TSoftObjectPtr<UObject> DefaultDisplayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> SoftTaskIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationTaskNode")
	TSoftObjectPtr<USoundBase> ChoiceSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationTaskNode")
	TSoftObjectPtr<USoundBase> HoverChoiceSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TSoftClassPtr<UUserWidget> BriefWidgetClassOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	TSoftClassPtr<UCommonActivatableWidget> SelectionWidgetClass;

};

