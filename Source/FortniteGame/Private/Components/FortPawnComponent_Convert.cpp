// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_Convert.h"
#include "Net/UnrealNetwork.h"

void UFortPawnComponent_Convert::AddToPreConversionFactions(const FGameplayTag& FactionTag)
{
}

void UFortPawnComponent_Convert::AppendConverterAbilitiesToAssignConverted(UFortAbilitySet* AbilitySetForConverted)
{
}

void UFortPawnComponent_Convert::AppendConverterAbilitiesToAssignConvertedWithTags(const FGameplayTagQuery& TagsMatchingConverted, UFortAbilitySet* AbilitySetForConverted)
{
}

float UFortPawnComponent_Convert::CalculateConvertDamageFromPickupTags(const FGameplayTagContainer& Tags, float Level) const
{
	return float();
}

void UFortPawnComponent_Convert::ClientRegisterConvertPawn_Implementation(AFortPawn* ConvertedPawn)
{
}

const TArray<AFortPawn*> UFortPawnComponent_Convert::GetConvertedPawns(const EConvertedType SpecificConvertedType) const
{
	return TArray<AFortPawn*>();
}

EConvertedType UFortPawnComponent_Convert::GetConvertedType() const
{
	return EConvertedType();
}

AFortPlayerPawn* UFortPawnComponent_Convert::GetConverterPawn() const
{
	return nullptr;
}

int32 UFortPawnComponent_Convert::GetMaxConvertedCreature() const
{
	return int32();
}

int32 UFortPawnComponent_Convert::GetMaxConvertedNPC() const
{
	return int32();
}

int32 UFortPawnComponent_Convert::GetNumConvertedPawns(const EConvertedType SpecificConvertedType) const
{
	return int32();
}

bool UFortPawnComponent_Convert::GetOnlyLeaderInteraction() const
{
	return false;
}

FLinearColor UFortPawnComponent_Convert::GetUIColor() const
{
	return FLinearColor();
}

void UFortPawnComponent_Convert::HandleControllerChanged(APawn* Pawn, AController* OldController, AController* NewController)
{
}

void UFortPawnComponent_Convert::HideIndicatorMarker()
{
}

void UFortPawnComponent_Convert::OnConvertedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortPawnComponent_Convert::OnConverterStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting)
{
}

void UFortPawnComponent_Convert::OnConverterStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting)
{
}

void UFortPawnComponent_Convert::OnConverterTeamChange()
{
}

void UFortPawnComponent_Convert::OnPingCommand_Implementation(PingCommandType CommandType)
{
}

void UFortPawnComponent_Convert::OnRep_ConverterPlayerInfo()
{
}

void UFortPawnComponent_Convert::RemoveFromPreConversionFactions(const FGameplayTag& FactionTag)
{
}

void UFortPawnComponent_Convert::ServerRequestReleaseAllConvertedPawns_Implementation(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason)
{
}
bool UFortPawnComponent_Convert::ServerRequestReleaseAllConvertedPawns_Validate(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason)
{
	return true;
}

void UFortPawnComponent_Convert::ServerRequestReleaseLastConvertedPawns_Implementation(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason)
{
}
bool UFortPawnComponent_Convert::ServerRequestReleaseLastConvertedPawns_Validate(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason)
{
	return true;
}

void UFortPawnComponent_Convert::SetCanBeConverted(const bool bInCanBeConverted)
{
}

void UFortPawnComponent_Convert::ShowIndicatorMarker()
{
}

void UFortPawnComponent_Convert::TriggerConversion(AFortPawn* Converter, AFortPawn* Converted, const bool bCanSteal)
{
}

void UFortPawnComponent_Convert::TriggerUnconversion(AFortPawn* Unconverter, AFortPawn* Unconverted)
{
}

void UFortPawnComponent_Convert::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_Convert, bCanConvert);
	DOREPLIFETIME(UFortPawnComponent_Convert, bCanBeConverted);
	DOREPLIFETIME(UFortPawnComponent_Convert, bCanBeConvertedFromDBNO);
	DOREPLIFETIME(UFortPawnComponent_Convert, ConverterPlayerInfo);
	DOREPLIFETIME(UFortPawnComponent_Convert, ConvertedPawnComponents);
	DOREPLIFETIME(UFortPawnComponent_Convert, PreviousConverters);
	DOREPLIFETIME(UFortPawnComponent_Convert, bOnlyLeaderInteraction);
}
