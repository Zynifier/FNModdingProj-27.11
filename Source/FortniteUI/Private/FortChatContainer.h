// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chat/SocialChatContainer.h"
#include "FortChatContainer.generated.h"

class UFortSocialInteractionMenu;
class UMenuAnchor;
class USocialChatChannel;
class UUserWidget;

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UFortChatContainer : public USocialChatContainer
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const FText GetTextChatDisabledText() const;

	UFUNCTION(BlueprintPure)
	bool IsTextChatRestricted() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSendButtonDisplayChanged(bool bShowSendButton);

	UPROPERTY()
	TWeakObjectPtr<USocialChatChannel> CacheChannelForPlatformMessage;

private:
	UFUNCTION()
	UUserWidget* HandleGetMenuContentForAnchor();

	UPROPERTY()
	TObjectPtr<USocialChatChannel> CombinedChannel;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialInteractionMenu> ActionMenuClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSocialInteractionMenu> ActionMenu;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UMenuAnchor> MenuAnchor_MessageActions;

};

