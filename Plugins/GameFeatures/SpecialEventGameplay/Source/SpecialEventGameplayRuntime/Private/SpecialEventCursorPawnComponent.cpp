// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventCursorPawnComponent.h"
#include "Net/UnrealNetwork.h"

USpecialEventCursorPawnComponent::USpecialEventCursorPawnComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool USpecialEventCursorPawnComponent::CanBeVisible() const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertNormalizedToViewportLocation(FVector2D& OutViewportLocation, const FVector2D& NormalizedLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertNormalizedToWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection, const FVector2D& NormalizedLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertViewportToNormalizedLocation(FVector2D& OutNormalizedLocation, const FVector2D& ViewportLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertViewportToWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection, const FVector2D& ViewportLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertWorldToNormalizedLocation(FVector2D& OutNormalizedLocation, const FVector& WorldLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::ConvertWorldToViewportLocation(FVector2D& OutViewportLocation, const FVector& WorldLocation) const
{
	return false;
}

UCameraComponent* USpecialEventCursorPawnComponent::GetCameraComponent() const
{
	return nullptr;
}

FVector2D USpecialEventCursorPawnComponent::GetCenteredWidgetLocation(UUserWidget* Widget, const FVector2D& ViewportLocation) const
{
	return FVector2D();
}

const FGameplayTag& USpecialEventCursorPawnComponent::GetCurrentCursorModeTag() const
{
	static FGameplayTag Dummy;
	return Dummy;
}

bool USpecialEventCursorPawnComponent::GetCurrentHitResult(FHitResult& OutHitResult)
{
	return false;
}

UUserWidget* USpecialEventCursorPawnComponent::GetCurrentWidget() const
{
	return nullptr;
}

FGameplayTagContainer USpecialEventCursorPawnComponent::GetCursorModeTagsForWidget(const UUserWidget* Widget) const
{
	return FGameplayTagContainer();
}

ECommonInputType USpecialEventCursorPawnComponent::GetInputType() const
{
	return ECommonInputType();
}

APlayerController* USpecialEventCursorPawnComponent::GetLocalController() const
{
	return nullptr;
}

FVector2D USpecialEventCursorPawnComponent::GetNormalizedLocation() const
{
	return FVector2D();
}

USpecialEventCursorPawnComponent* USpecialEventCursorPawnComponent::GetSpecialEventCursorPawnComponent(const APawn* Pawn, const FGameplayTag& CursorModeTag, const bool bMustBeActive)
{
	return nullptr;
}

bool USpecialEventCursorPawnComponent::GetViewportCenter(FVector2D& OutViewportCenter) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::GetViewportLocation(FVector2D& OutViewportLocation) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::GetViewportSize(FVector2D& OutViewportSize) const
{
	return false;
}

bool USpecialEventCursorPawnComponent::GetWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection) const
{
	return false;
}

void USpecialEventCursorPawnComponent::GyroInputUpdate(const FVector& InInputVector)
{
}

void USpecialEventCursorPawnComponent::InputPressed(const FName& ActionName, const bool bPressed)
{
}

bool USpecialEventCursorPawnComponent::IsAdditiveRotationAllowed() const
{
	return false;
}

bool USpecialEventCursorPawnComponent::IsLocallyControlled() const
{
	return false;
}

bool USpecialEventCursorPawnComponent::IsZoomAllowed() const
{
	return false;
}

void USpecialEventCursorPawnComponent::LookInputUpdate(const FVector& InInputVector)
{
}

void USpecialEventCursorPawnComponent::MoveInputUpdate(const FVector& InInputVector)
{
}

void USpecialEventCursorPawnComponent::OnHUDPostRender(AHUD* HUD, UCanvas* Canvas)
{
}

void USpecialEventCursorPawnComponent::OnInputMethodChanged(ECommonInputType InputType)
{
}

void USpecialEventCursorPawnComponent::OnLocallyControlledCursorVisibilityChanged(USpecialEventCursorPawnComponent* CursorPawnComponent, const FGameplayTag& CursorModeTag, const bool bShouldBeVisible)
{
}

void USpecialEventCursorPawnComponent::OnRep_bAllowOnNonOwningClients()
{
}

void USpecialEventCursorPawnComponent::OnRep_ReplicatedCursorStackEntry(const FSpecialEventCursorStackEntry& OldCursorStackEntry)
{
}

void USpecialEventCursorPawnComponent::OnRep_ReplicatedWorldLocation()
{
}

void USpecialEventCursorPawnComponent::PopAllCursorsForObject(UObject* InstigatingObject, const bool bDeactivateIfStackEmpty)
{
}

void USpecialEventCursorPawnComponent::PopCursor(const FGameplayTag& CursorModeTag, UObject* InstigatingObject, const bool bDeactivateIfStackEmpty)
{
}

void USpecialEventCursorPawnComponent::PushCursor(const FGameplayTag& CursorModeTag, UObject* InstigatingObject, const bool bActivate)
{
}

void USpecialEventCursorPawnComponent::ServerOnWorldLocationChanged_Implementation(const FVector& WorldLocation)
{
}

void USpecialEventCursorPawnComponent::SetAdditiveRotationAllowed(const bool bInAdditiveRotationAllowed)
{
}

void USpecialEventCursorPawnComponent::SetAllowOnNonOwningClients(const bool bAllow)
{
}

void USpecialEventCursorPawnComponent::SetZoomAllowed(const bool bInZoomAllowed)
{
}

void USpecialEventCursorPawnComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialEventCursorPawnComponent, bAllowOnNonOwningClients);
	DOREPLIFETIME(USpecialEventCursorPawnComponent, ReplicatedCursorStackEntry);
	DOREPLIFETIME(USpecialEventCursorPawnComponent, ReplicatedWorldLocation);
}
