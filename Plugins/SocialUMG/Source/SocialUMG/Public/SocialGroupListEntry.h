// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "SocialGroupListEntry.generated.h"

class UMenuAnchor;
class USocialActionMenu;
class USocialGroupChannel;
class UTextBlock;
class UUserWidget;

UCLASS(Abstract)
class SOCIALUMG_API USocialGroupListEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SocialGroupListEntry")
	TSubclassOf<USocialActionMenu> ActionMenuClass;

protected:
	UFUNCTION()
	UUserWidget* HandleGetMenuContent();

	UPROPERTY()
	TObjectPtr<USocialGroupChannel> SocialGroup;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialGroupListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_GroupName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> MenuAnchor_Actions;

};

