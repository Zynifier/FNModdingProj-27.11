// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "UObject/NoExportTypes.h"
#include "FortShowdownTournamentListView.generated.h"

class UFortShowdownTournamentTile;
class UObject;
class UUserWidget;

UCLASS(meta=(DisableNativeTick, EntryClass="FortShowdownTournamentTile"))
class UFortShowdownTournamentListView : public UCommonListView
{
	GENERATED_BODY()

public:
	UFortShowdownTournamentListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	UFortShowdownTournamentTile* FindTournament(const FString& TournamentId) const;

	UFUNCTION(BlueprintPure)
	float GetDesiredScrollOffset(int32 Index) const;

	UFUNCTION(BlueprintPure)
	bool IsSelectedItemFirstRow() const;

	UFUNCTION(BlueprintPure)
	bool IsSelectedItemLastRow() const;

	UFUNCTION(BlueprintCallable)
	UFortShowdownTournamentTile* NavigateTournamentLeft();

	UFUNCTION(BlueprintCallable)
	UFortShowdownTournamentTile* NavigateTournamentRight();

	UFUNCTION(BlueprintCallable)
	void ScrollItemToDesiredOffset(UObject* InObject);

	UFUNCTION(BlueprintCallable)
	UFortShowdownTournamentTile* SelectFirstTournament();

	UFUNCTION(BlueprintCallable)
	UFortShowdownTournamentTile* SelectLastTournament();

	UFUNCTION(BlueprintCallable)
	UFortShowdownTournamentTile* SelectTournamentAtIndex(const int32 SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void SetScrollOffsetAnimation(const bool bEnable);

	UPROPERTY(EditAnywhere, Category="FortShowdownTournamentListView", meta=(ClampMin="1"))
	float EntryWidthSize;

	UPROPERTY(EditAnywhere, Category="FortShowdownTournamentListView")
	int32 NumPaddingRowLeft;

	UPROPERTY(EditAnywhere, Category="FortShowdownTournamentListView")
	int32 NumPaddingRowRight;

	UPROPERTY(EditAnywhere, Category="FortShowdownTournamentListView")
	bool bCanUseDesiredScrollOffset;

protected:
	UFUNCTION(BlueprintPure)
	UUserWidget* GetEntryAtIndex(int32 SelectedIndex) const;

};

UCLASS(BlueprintType)
class UTournamentListEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="TournamentListEntryData")
	bool bHideItemRow;

};

