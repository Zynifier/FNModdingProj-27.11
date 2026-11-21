// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortAffiliateModal.generated.h"

class UCommonButtonBase;
class UEditableText;
class UListView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAffilateModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAffilateModal", meta=(ExposeOnSpawn))
	FString SourceName;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAffilateModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> AcceptButton;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAffilateModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> AffiliateKey;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAffilateModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> AffiliateSuggestionList;

};

UCLASS()
class UFortAffiliateEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortAffiliateEntryData")
	FString AffiliateName;

};

