// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonListView.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "Quests/FortQuestTypes.h"
#include "AthenaAccoladeListWidget.generated.h"

class UFortAccoladeItemDefinition;

UCLASS(meta=(DisableNativeTick))
class UAthenaAccoladeListEntryWidget : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCount(int32 Count);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetIcon(const UFortAccoladeItemDefinition* ItemDef);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSource(const FText& SourceText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetTitle(const FText& TitleText);

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick, EntryClass="AthenaAccoladeListEntryWidget"))
class UAthenaAccoladeListWidget : public UCommonListView
{
	GENERATED_BODY()

public:
	UAthenaAccoladeListWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void PopulateWidget();

};

UCLASS()
class UAthenaAccoladeWrapper : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FAthenaAccolades AccoladeData;

};

